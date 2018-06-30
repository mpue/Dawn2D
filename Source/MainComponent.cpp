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
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
    texture.release();
    texture.unbind();
    
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
    texture.bind();
    // Draw a textured quad
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
    glTexCoord2f(0, 1); glVertex3f(0, 100, 0);
    glTexCoord2f(1, 1); glVertex3f(100, 100, 0);
    glTexCoord2f(1, 0); glVertex3f(100, 0, 0);
    glEnd();
    
    
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
