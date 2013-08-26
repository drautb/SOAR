#include <GLFW/glfw3.h>

#include "Log.h"
#include "Scene.h"

using namespace SOAR;
using namespace Video;

void Scene::Enable2D()
{
    // Make sure that the GL_NV_texture_rectangle extension is supported
    if (!glfwExtensionSupported("GL_NV_texture_rectangle"))
    {
        SOAR_LOG_FATAL << "GL_NV_texture_rectangle extension is not supported!";
        return;
    }

    GLint iViewport[4];

    // Get a copy of the viewport
    glGetIntegerv(GL_VIEWPORT, iViewport);

    // Save a copy of the projection matrix so that we can restore it 
    // when it's time to do 3D rendering again.
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    // Set up the orthographic projection
    glOrtho(iViewport[0], iViewport[0]+iViewport[2],
            iViewport[1]+iViewport[3], iViewport[1], -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Make sure depth testing and lighting are disabled for 2D rendering until
    // we are finished rendering in 2D
    glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_DITHER);
    glDisable(GL_BLEND);
}

void Scene::Disable2D()
{
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}
