#ifndef _RHAPSODIES_HANDMODEL
#define _RHAPSODIES_HANDMODEL

#include <vector>

#include <VistaBase/VistaVector3D.h>
#include <VistaBase/VistaQuaternion.h>

namespace rhapsodies {
  class HandModel {
  public:
	  HandModel();

	  /* JointDOF indices are named as: FINGER_JOINT[_DIRECTION]
	   * 
	   * FINGER is one of:
	   * T (thumb)
	   * I (index)
	   * M (middle)
	   * R (ring)
	   * L (little)
	   *
	   * JOINT is one of:
	   * CMC (carpometacarpal)
	   * MCP (metacarpophalangeal)
	   * IP  (interphalangeal)
	   * PIP (proximal interphalangeal)
	   * DIP (distal interphalangeal)
	   *
	   * DIRECTION optional and one of:
	   * A (abduction)
	   * F (flexion)
	   */
	  enum JointDOF {
		  T_CMC_F,
		  T_CMC_A,
		  T_MCP,
		  T_IP,
		  I_MCP_F,
		  I_MCP_A,
		  I_PIP,
		  I_DIP,
		  M_MCP_F,
		  M_MCP_A,
		  M_PIP,
		  M_DIP,
		  R_MCP_F,
		  R_MCP_A,
		  R_PIP,
		  R_DIP,
		  L_MCP_F,
		  L_MCP_A,
		  L_PIP,
		  L_DIP
	  };

	  enum HandOrientation {
		  LEFT_HAND,
		  RIGHT_HAND
	  };
	  
	  float GetJointAngle(JointDOF dof);
	  void SetJointAngle(JointDOF dof, float angle);

	  

  private:
	  std::vector<float> m_vecJointAngles;
	  VistaVector3D   m_vPosition;
	  VistaQuaternion m_qOrientation;
  };
}

#endif // _RHAPSODIES_HANDMODEL
