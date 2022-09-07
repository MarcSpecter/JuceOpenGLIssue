/*
  ==============================================================================

    openGLComponent.cpp
    Created: 15 Jun 2022 10:05:11pm
    Author:  Marc Specter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "openGLComponent.h"


using namespace juce;
using namespace ::juce::gl;

//==============================================================================
openGLComponent::openGLComponent(kWaveViewInterface* iface):interface(iface)
{
    openGLContext.setRenderer (this);
    openGLContext.attachTo (*this);
    
    openGLContext.setComponentPaintingEnabled(false);
    
    //InitRenderer(); //this crashes cos of no glcontext i think. lazy init in the render func instead.
    
}

openGLComponent::~openGLComponent()
{
    openGLContext.detach();
}

void openGLComponent::newOpenGLContextCreated(){
//    desktopScale = (float) openGLContext.getRenderingScale();
    

}
void openGLComponent::openGLContextClosing(){
};

void openGLComponent::renderOpenGL(){
    static int ffff;
    std::cout<<"paint renderOPENGL"<<++ffff<<" \n";

//    SetBlendFunc();    //needed every frame - now done in clear()
    ////////////////////////////////////////////////////////
    
    desktopScale = (float) openGLContext.getRenderingScale();   //needed every frame
    int w = roundToInt (desktopScale * (float)getWidth());
    int h = roundToInt (desktopScale * (float)getHeight());


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);


    glClearColor(0.0, 0.0, 0.0, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport (0, 0,
                roundToInt (desktopScale * (float)getWidth()),
                roundToInt (desktopScale * (float)getHeight()));

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex2f(0.0,0.0);

    glColor3f(0,0,1);

    glVertex2f(1,0.0);
    glColor3f(0,1,0);

    glVertex2f(1,1);

    glEnd();

    
}

//
//void openGLComponent::paint (juce::Graphics& g)
//{
//
//}

void openGLComponent::resized()
{
    static int cc;
    std::cout << "OPENGL resize"<<++cc<<"\n";
    int w = roundToInt (desktopScale * (float)getWidth());
    int h = roundToInt (desktopScale * (float)getHeight());
    
    
}
void openGLComponent::mouseDown  (const MouseEvent& e){
    if(e.mods.isRightButtonDown()){
        getParentComponent()->mouseDown(e);
    }else{
    }
}
void openGLComponent::mouseUp  (const MouseEvent& e){
}

void openGLComponent::mouseDrag  (const MouseEvent& e){
    float x = e.x;//>e.y?e.x:0;
    float y = e.y;//>e.x?e.y:0;
}
void openGLComponent::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel){
    //TODO: mousewheel move ended is not provided by juce. Need to simulate it.
 
}

