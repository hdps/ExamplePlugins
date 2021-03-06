#include "ExampleLoaderPlugin.h"

#include "PointData.h"
#include "Set.h"

#include <QtCore>
#include <QtDebug>

#include <random>

Q_PLUGIN_METADATA(IID "nl.tudelft.ExampleLoaderPlugin")

using namespace hdps;

// =============================================================================
// View
// =============================================================================

ExampleLoaderPlugin::~ExampleLoaderPlugin(void)
{
    
}

/**
 * Mandatory plugin override function. Any initial state can be set here.
 * This function gets called when an instance of the plugin is created.
 * In this case when someone select the loader option from the menu.
 */
void ExampleLoaderPlugin::init()
{

}

/**
 * Mandatory override function. Gets called when someone selects the Example Loader option
 * from the menu containing loader plugins. This function is responsible for opening the
 * file(s) the user wants to open, process them appropriately and pass the final data to the core.
 */
void ExampleLoaderPlugin::loadData()
{
    QString name = _core->addData("Points", "ExampleData");
    qDebug() << name;
    Points& points = _core->requestData<Points>(name);

    // Create 2D example data by randomly generating 1000 points
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution;

    int numPoints = 1000;
    int numDimensions = 2;

    std::vector<float> exampleData;
    for (int i = 0; i < numPoints * numDimensions; i++)
    {
        exampleData.push_back(distribution(generator));
    }

    // Passing example data with 1000 points and 2 dimensions
    points.setData(exampleData.data(), numPoints, numDimensions);

    qDebug() << "Number of dimensions: " << points.getNumDimensions();

    // Notify the core system of the new data
    _core->notifyDataAdded(name);

    qDebug() << "Example file loaded. Num data points: " << points.getNumPoints();
}

// =============================================================================
// Factory DOES NOT NEED TO BE ALTERED
// Merely responsible for generating new plugins when requested
// =============================================================================

ExampleLoaderPlugin* ExampleLoaderPluginFactory::produce()
{
    return new ExampleLoaderPlugin();
}
