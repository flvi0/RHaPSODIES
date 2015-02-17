#ifndef _RHAPSODIES_HANDRENDERER
#define _RHAPSODIES_HANDRENDERER

#include <vector>

#include <GL/gl.h>

#include <VistaBase/VistaTransformMatrix.h>
#include <VistaKernel/GraphicsManager/VistaOpenGLDraw.h>

class ShaderRegistry;

namespace rhapsodies {
	class HandModel;
	
	class HandRenderer : public IVistaOpenGLDraw {
	public:
		HandRenderer(HandModel *pModelLeft,
					 HandModel *pModelRight,
					 ShaderRegistry *pReg);
		
		virtual bool Do();
		virtual bool GetBoundingBox(VistaBoundingBox &bb);

		// HandModel* GetModel();
		// void SetModel(HandModel* pModel);
		
	private:
		enum BufferObjectId {
			SPHERE,
			CYLINDER,
			BUFFER_OBJECT_LAST
		};
		
		void PrepareVertexBufferObjects();
		inline void DrawSphere(VistaTransformMatrix matModel,
							   GLint locUniform);
		inline void DrawCylinder(VistaTransformMatrix matModel,
								 GLint locUniform);
		inline void DrawFinger(VistaTransformMatrix matOrigin,
							   float fFingerDiameter, float fLRFactor,
							   float fAng1F, float fAng1A, float fLen1,
							   float fAng2, float fLen2,
							   float fAng3, float fLen3,
							   bool bThumb);
		inline void DrawHand(HandModel *pModel);

		HandModel *m_pModelLeft;
		HandModel *m_pModelRight;
		ShaderRegistry *m_pShaderReg;

		std::vector<float> m_vSphereVertexData;
		std::vector<float> m_vCylinderVertexData;
		
		GLuint m_idVertexArrayObjects[BUFFER_OBJECT_LAST];
		GLuint m_idBufferObjects[BUFFER_OBJECT_LAST];
	};
}

#endif // _RHAPSODIES_HANDRENDERER
