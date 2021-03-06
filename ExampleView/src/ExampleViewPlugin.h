#pragma once

#include <ViewPlugin.h>

#include <QPushButton>

using namespace hdps::plugin;

// =============================================================================
// Example Widget
// =============================================================================

class ExampleWidget : public QPushButton
{
public:
    ExampleWidget()
    {
        setFixedSize(300, 200);
        setText("You successfully built the application!");
    }
};


// =============================================================================
// View
// =============================================================================

class ExampleViewPlugin : public ViewPlugin
{
    Q_OBJECT
    
public:
    ExampleViewPlugin() : ViewPlugin("Example View") { }
    ~ExampleViewPlugin(void) override;
    
    void init() override;

    void onDataEvent(hdps::DataEvent* dataEvent);
};


// =============================================================================
// Factory
// =============================================================================

class ExampleViewPluginFactory : public ViewPluginFactory
{
    Q_INTERFACES(hdps::plugin::ViewPluginFactory hdps::plugin::PluginFactory)
    Q_OBJECT
    Q_PLUGIN_METADATA(IID   "nl.tudelft.ExampleViewPlugin"
                      FILE  "ExampleViewPlugin.json")
    
public:
    ExampleViewPluginFactory(void) {}
    ~ExampleViewPluginFactory(void) override {}
    
    ViewPlugin* produce() override;
};
