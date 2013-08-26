#ifndef SCENE_H
#define SCENE_H

namespace SOAR
{
    namespace Video
    {
        /**
         * This class just contains a couple of helper
         * methods for setting up 2D rendering. 
         * @see http://www.gamedev.net/page/resources/_/technical/opengl/rendering-efficient-2d-sprites-in-opengl-using-r2429
         */
        class Scene
        {
        public:
        
            /**
             * Saves and resets everything for 2D rendering
             */
            static void Enable2D();

            /**
             * Restores everything for 3D rendering
             */
            static void Disable2D();
        };
    }
}

#endif
