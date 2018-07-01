/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public OpenGLAppComponent, public KeyListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void initialise() override;
    void shutdown() override;
    void render() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

    virtual bool keyPressed (const KeyPress& key, Component* originatingComponent) override;
    virtual bool keyStateChanged(bool isKeyDown, juce::Component *originatingComponent) override;
private:
    //==============================================================================
    // Your private member variables go here...
    OpenGLTexture texture;
    OpenGLTexture background;
    
    float player_x = 0;
    float player_y = 0;
    
    float offset_x = 0;
    float offset_y = -1000;
    
    float scroll_speed = 10.0f;
    float speed = 5.0f;
    
    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
