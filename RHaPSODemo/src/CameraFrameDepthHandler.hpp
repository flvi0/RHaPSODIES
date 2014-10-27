/*============================================================================*/
/*                  Copyright (c) 2014 RWTH Aachen University                 */
/*============================================================================*/
/*                                  License                                   */
/*                                                                            */
/*  This program is free software: you can redistribute it and/or modify      */
/*  it under the terms of the GNU Lesser General Public License as published  */
/*  by the Free Software Foundation, either version 3 of the License, or      */
/*  (at your option) any later version.                                       */
/*                                                                            */
/*  This program is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/*  GNU Lesser General Public License for more details.                       */
/*                                                                            */
/*  You should have received a copy of the GNU Lesser General Public License  */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.     */
/*============================================================================*/
/*                                Contributors                                */
/*                                                                            */
/*============================================================================*/
// $Id: $

#ifndef _RHAPSODIES_CAMERAFRAMEDEPTHHANDLER
#define _RHAPSODIES_CAMERAFRAMEDEPTHHANDLER

#include <CameraFrameHandler.hpp>

// @todo forward declare the data series, mon!
#include <Vfl2DDiagrams/Data/V2dDataSeriesTypes.h>

class V2dDiagramDefault;
class V2dDiagramTextureVista;

namespace rhapsodies {
	class ImagePBOOpenGLDraw;
	class HistogramUpdater;

	class CameraFrameDepthHandler :
		public CameraFrameHandler {
		unsigned char *m_pBuffer;

		V2dDiagramDefault *m_pDiagram;
		V2dDiagramTextureVista *m_pDiagramTexture;
		V2dDataSeriesIntContinuousOverString *m_pDataSeries;

		int m_iHistDrawCounter;
		int m_iHistDrawInterval;
		int m_iHistNumBins;
		HistogramUpdater *m_pHistUpdater;
		
	public:
		CameraFrameDepthHandler(openni::VideoStream *pStream,
								ImagePBOOpenGLDraw *pDraw);
		virtual ~CameraFrameDepthHandler();

		virtual void onNewFrame(openni::VideoStream &);

		V2dDiagramTextureVista *GetDiagramTexture();
		HistogramUpdater *GetHistogramUpdater();
	};
}

#endif // _RHAPSODIES_CAMERAFRAMEDEPTHHANDLER