/***** BEGIN LICENSE BLOCK *****

BSD License

Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the NIF File Format Library and Tools projectmay not be
   used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***** END LICENCE BLOCK *****/

#ifndef GLMESH_H
#define GLMESH_H

#include "glnode.h"

class Mesh : public Node
{
	class Tristrip
	{
	public:
		Tristrip() {}
		Tristrip( const NifModel * nif, const QModelIndex & );
		QVector<quint16> vertices;
	};
public:
	Mesh( Scene * s, const QModelIndex & b ) : Node( s, b ) {}
	
	void clear();
	void update( const NifModel * nif, const QModelIndex & );
	
	void transform();
	void transformShapes();
	
	void drawShapes( NodeList * draw2nd = 0 );
	
	bool isHidden() const;
	
	BoundSphere bounds() const;
	
protected:	
	void setController( const NifModel * nif, const QModelIndex & controller );
	
	QPersistentModelIndex iData, iSkin, iSkinData;
	bool upData, upSkin;
	
	QVector<Vector3> verts;
	QVector<Vector3> norms;
	QVector<Color4>  colors;
	QVector<Vector2> coords;
	
	QVector<Vector3> transVerts;
	QVector<Vector3> transNorms;
	QVector<Color4> transColors;
	QVector<Vector2> transCoords;
	
	Vector2 texOffset;
	
	int skelRoot;
	Transform skelTrans;
	QVector<BoneWeights> weights;
	
	QVector<Triangle> triangles;
	QVector<Tristrip> tristrips;
	
	QVector< QPair< int, float > > triOrder;
	
	bool transformRigid;
	
	mutable BoundSphere bndSphere;
	mutable bool upBounds;
	
	friend class MorphController;
	friend class TexCoordController;
};

#endif