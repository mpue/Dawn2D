 /*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <GLUT/GLUT.h>
//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    addKeyListener(this);
    setWantsKeyboardFocus(true);
}

MainComponent::~MainComponent()
{
    // This shuts down the GL system and stops the rendering calls.
    shutdownOpenGL();
}

//==============================================================================
void MainComponent::initialise()
{
    // Initialise GL objects for rendering here.
   
    texture.bind();

    Image im = ImageCache::getFromMemory(BinaryData::test_png, BinaryData::test_pngSize);

    texture.loadImage (im);
    
    background.bind();
    
    Image bg = ImageCache::getFromMemory(BinaryData::dawn_beta_part13_jpg, BinaryData::dawn_beta_part13_jpgSize);
    
    background.loadImage(bg);
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
    texture.release();
    texture.unbind();
    
    background.release();
    background.unbind();
    
}

void MainComponent::render()
{
    // This clears the context with a black background.
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0.0, getWidth(), 0.0, getHeight(), 0, 100);
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);

    background.bind();

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0 + offset_x, 0 + offset_y, 0);
    glTexCoord2f(0, 1); glVertex3f(0 + offset_x, background.getHeight() + offset_y, 0);
    glTexCoord2f(1, 1); glVertex3f(background.getWidth() + offset_x, background.getHeight() + offset_y, 0);
    glTexCoord2f(1, 0); glVertex3f(background.getWidth() + offset_x, 0 + offset_y, 0);
    glEnd();


    // player
    texture.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0 + player_x, 0 + player_y, 0);
    glTexCoord2f(0, 1); glVertex3f(0 + player_x, 100 + player_y, 0);
    glTexCoord2f(1, 1); glVertex3f(100 + player_x, 100 + player_y, 0);
    glTexCoord2f(1, 0); glVertex3f(100 + player_x, 0 + player_y, 0);
    glEnd();
    
    if (movingDown) {
        if (player_y < getHeight() * 0.25 - 100) {
            offset_y += scroll_speed;
        }
        else {
            if (player_y > 0)
                player_y -= speed;
        }
    }
    else if (movingUp) {
        if (player_y > getHeight() * 0.75) {
            offset_y -= scroll_speed;
        }
        else {
            if (player_y < getHeight() - 100)
                player_y += speed;
        }
    }
    
    if (movingLeft) {
        if (player_x < getWidth() * 0.25 - 100) {
            offset_x += speed;
        }
        else {
            if (player_x > 0)
                player_x -= speed;
        }
    }
    else if(movingRight) {

        if (player_x > getWidth() * 0.75) {
            offset_x -= speed;
        }
        else {
            if (player_x < getWidth() - 100)
                player_x += speed;
        }
        
    }
    
    // Add your rendering code here...
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

bool MainComponent::keyPressed(const juce::KeyPress &key, juce::Component *originatingComponent) {
    
    if (key.getKeyCode() == KeyPress::leftKey) {
        
    }
    if (key.getKeyCode() == KeyPress::rightKey) {

    }
    if (key.getKeyCode() == KeyPress::upKey) {

    }
    if (key.getKeyCode() == KeyPress::downKey) {

    }
    
    return true;
}

bool MainComponent::keyStateChanged(bool isKeyDown, juce::Component *originatingComponent) {
    if(KeyPress::isKeyCurrentlyDown(KeyPress::leftKey)) {
        movingLeft = true;
    }
    else {
        movingLeft = false;
    }
    if(KeyPress::isKeyCurrentlyDown(KeyPress::rightKey)) {
        movingRight = true;
    }
    else {
        movingRight = false;
    }
    if(KeyPress::isKeyCurrentlyDown(KeyPress::upKey)) {
        movingUp = true;
    }
    else {
        movingUp = false;
    }
    if(KeyPress::isKeyCurrentlyDown(KeyPress::downKey)) {
        movingDown = true;
    }
    else {
        movingDown = false;
    }
    
    
}
