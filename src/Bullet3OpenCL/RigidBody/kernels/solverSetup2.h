//this file is autogenerated using stringify.bat (premake --stringify) in the build folder of this project
static const char* solverSetup2CL= \
"/*\n"
"Copyright (c) 2012 Advanced Micro Devices, Inc.  \n"
"This software is provided 'as-is', without any express or implied warranty.\n"
"In no event will the authors be held liable for any damages arising from the use of this software.\n"
"Permission is granted to anyone to use this software for any purpose, \n"
"including commercial applications, and to alter it and redistribute it freely, \n"
"subject to the following restrictions:\n"
"1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.\n"
"2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.\n"
"3. This notice may not be removed or altered from any source distribution.\n"
"*/\n"
"//Originally written by Takahiro Harada\n"
"#ifndef B3_CONTACT4DATA_H\n"
"#define B3_CONTACT4DATA_H\n"
"#ifndef B3_FLOAT4_H\n"
"#define B3_FLOAT4_H\n"
"#ifndef B3_PLATFORM_DEFINITIONS_H\n"
"#define B3_PLATFORM_DEFINITIONS_H\n"
"struct MyTest\n"
"{\n"
"	int bla;\n"
"};\n"
"#endif\n"
"#ifdef __cplusplus\n"
"#else//bla\n"
"	typedef float4	b3Float4;\n"
"#endif \n"
"#endif //B3_FLOAT4_H\n"
"typedef  struct b3Contact4Data b3Contact4Data_t;\n"
"struct b3Contact4Data\n"
"{\n"
"	b3Float4	m_worldPos[4];\n"
"//	b3Float4	m_localPosB[4];\n"
"	b3Float4	m_worldNormal;	//	w: m_nPoints\n"
"	unsigned short  m_restituitionCoeffCmp;\n"
"	unsigned short  m_frictionCoeffCmp;\n"
"	int m_batchIdx;\n"
"	int m_bodyAPtrAndSignBit;//x:m_bodyAPtr, y:m_bodyBPtr\n"
"	int m_bodyBPtrAndSignBit;\n"
"	int	m_childIndexA;\n"
"	int	m_childIndexB;\n"
"	int m_unused1;\n"
"	int m_unused2;\n"
"	b3Float4	m_localPosA;\n"
"};\n"
"inline int b3Contact4Data_getNumPoints(const struct b3Contact4Data* contact)\n"
"{\n"
"	return (int)contact->m_worldNormal.w;\n"
"};\n"
"inline void b3Contact4Data_setNumPoints(struct b3Contact4Data* contact, int numPoints)\n"
"{\n"
"	contact->m_worldNormal.w = (float)numPoints;\n"
"};\n"
"#endif //B3_CONTACT4DATA_H\n"
"#pragma OPENCL EXTENSION cl_amd_printf : enable\n"
"#pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics : enable\n"
"#pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics : enable\n"
"#pragma OPENCL EXTENSION cl_khr_local_int32_extended_atomics : enable\n"
"#pragma OPENCL EXTENSION cl_khr_global_int32_extended_atomics : enable\n"
"#ifdef cl_ext_atomic_counters_32\n"
"#pragma OPENCL EXTENSION cl_ext_atomic_counters_32 : enable\n"
"#else\n"
"#define counter32_t volatile global int*\n"
"#endif\n"
"typedef unsigned int u32;\n"
"typedef unsigned short u16;\n"
"typedef unsigned char u8;\n"
"#define GET_GROUP_IDX get_group_id(0)\n"
"#define GET_LOCAL_IDX get_local_id(0)\n"
"#define GET_GLOBAL_IDX get_global_id(0)\n"
"#define GET_GROUP_SIZE get_local_size(0)\n"
"#define GET_NUM_GROUPS get_num_groups(0)\n"
"#define GROUP_LDS_BARRIER barrier(CLK_LOCAL_MEM_FENCE)\n"
"#define GROUP_MEM_FENCE mem_fence(CLK_LOCAL_MEM_FENCE)\n"
"#define AtomInc(x) atom_inc(&(x))\n"
"#define AtomInc1(x, out) out = atom_inc(&(x))\n"
"#define AppendInc(x, out) out = atomic_inc(x)\n"
"#define AtomAdd(x, value) atom_add(&(x), value)\n"
"#define AtomCmpxhg(x, cmp, value) atom_cmpxchg( &(x), cmp, value )\n"
"#define AtomXhg(x, value) atom_xchg ( &(x), value )\n"
"#define SELECT_UINT4( b, a, condition ) select( b,a,condition )\n"
"#define make_float4 (float4)\n"
"#define make_float2 (float2)\n"
"#define make_uint4 (uint4)\n"
"#define make_int4 (int4)\n"
"#define make_uint2 (uint2)\n"
"#define make_int2 (int2)\n"
"#define max2 max\n"
"#define min2 min\n"
"///////////////////////////////////////\n"
"//	Vector\n"
"///////////////////////////////////////\n"
"__inline\n"
"float fastDiv(float numerator, float denominator)\n"
"{\n"
"	return native_divide(numerator, denominator);	\n"
"//	return numerator/denominator;	\n"
"}\n"
"__inline\n"
"float4 fastDiv4(float4 numerator, float4 denominator)\n"
"{\n"
"	return native_divide(numerator, denominator);	\n"
"}\n"
"__inline\n"
"float fastSqrtf(float f2)\n"
"{\n"
"	return native_sqrt(f2);\n"
"//	return sqrt(f2);\n"
"}\n"
"__inline\n"
"float fastRSqrt(float f2)\n"
"{\n"
"	return native_rsqrt(f2);\n"
"}\n"
"__inline\n"
"float fastLength4(float4 v)\n"
"{\n"
"	return fast_length(v);\n"
"}\n"
"__inline\n"
"float4 fastNormalize4(float4 v)\n"
"{\n"
"	return fast_normalize(v);\n"
"}\n"
"__inline\n"
"float sqrtf(float a)\n"
"{\n"
"//	return sqrt(a);\n"
"	return native_sqrt(a);\n"
"}\n"
"__inline\n"
"float4 cross3(float4 a, float4 b)\n"
"{\n"
"	return cross(a,b);\n"
"}\n"
"__inline\n"
"float dot3F4(float4 a, float4 b)\n"
"{\n"
"	float4 a1 = make_float4(a.xyz,0.f);\n"
"	float4 b1 = make_float4(b.xyz,0.f);\n"
"	return dot(a1, b1);\n"
"}\n"
"__inline\n"
"float length3(const float4 a)\n"
"{\n"
"	return sqrtf(dot3F4(a,a));\n"
"}\n"
"__inline\n"
"float dot4(const float4 a, const float4 b)\n"
"{\n"
"	return dot( a, b );\n"
"}\n"
"//	for height\n"
"__inline\n"
"float dot3w1(const float4 point, const float4 eqn)\n"
"{\n"
"	return dot3F4(point,eqn) + eqn.w;\n"
"}\n"
"__inline\n"
"float4 normalize3(const float4 a)\n"
"{\n"
"	float4 n = make_float4(a.x, a.y, a.z, 0.f);\n"
"	return fastNormalize4( n );\n"
"//	float length = sqrtf(dot3F4(a, a));\n"
"//	return 1.f/length * a;\n"
"}\n"
"__inline\n"
"float4 normalize4(const float4 a)\n"
"{\n"
"	float length = sqrtf(dot4(a, a));\n"
"	return 1.f/length * a;\n"
"}\n"
"__inline\n"
"float4 createEquation(const float4 a, const float4 b, const float4 c)\n"
"{\n"
"	float4 eqn;\n"
"	float4 ab = b-a;\n"
"	float4 ac = c-a;\n"
"	eqn = normalize3( cross3(ab, ac) );\n"
"	eqn.w = -dot3F4(eqn,a);\n"
"	return eqn;\n"
"}\n"
"///////////////////////////////////////\n"
"//	Matrix3x3\n"
"///////////////////////////////////////\n"
"typedef struct\n"
"{\n"
"	float4 m_row[3];\n"
"}Matrix3x3;\n"
"__inline\n"
"Matrix3x3 mtZero();\n"
"__inline\n"
"Matrix3x3 mtIdentity();\n"
"__inline\n"
"Matrix3x3 mtTranspose(Matrix3x3 m);\n"
"__inline\n"
"Matrix3x3 mtMul(Matrix3x3 a, Matrix3x3 b);\n"
"__inline\n"
"float4 mtMul1(Matrix3x3 a, float4 b);\n"
"__inline\n"
"float4 mtMul3(float4 a, Matrix3x3 b);\n"
"__inline\n"
"Matrix3x3 mtZero()\n"
"{\n"
"	Matrix3x3 m;\n"
"	m.m_row[0] = (float4)(0.f);\n"
"	m.m_row[1] = (float4)(0.f);\n"
"	m.m_row[2] = (float4)(0.f);\n"
"	return m;\n"
"}\n"
"__inline\n"
"Matrix3x3 mtIdentity()\n"
"{\n"
"	Matrix3x3 m;\n"
"	m.m_row[0] = (float4)(1,0,0,0);\n"
"	m.m_row[1] = (float4)(0,1,0,0);\n"
"	m.m_row[2] = (float4)(0,0,1,0);\n"
"	return m;\n"
"}\n"
"__inline\n"
"Matrix3x3 mtTranspose(Matrix3x3 m)\n"
"{\n"
"	Matrix3x3 out;\n"
"	out.m_row[0] = (float4)(m.m_row[0].x, m.m_row[1].x, m.m_row[2].x, 0.f);\n"
"	out.m_row[1] = (float4)(m.m_row[0].y, m.m_row[1].y, m.m_row[2].y, 0.f);\n"
"	out.m_row[2] = (float4)(m.m_row[0].z, m.m_row[1].z, m.m_row[2].z, 0.f);\n"
"	return out;\n"
"}\n"
"__inline\n"
"Matrix3x3 mtMul(Matrix3x3 a, Matrix3x3 b)\n"
"{\n"
"	Matrix3x3 transB;\n"
"	transB = mtTranspose( b );\n"
"	Matrix3x3 ans;\n"
"	//	why this doesn't run when 0ing in the for{}\n"
"	a.m_row[0].w = 0.f;\n"
"	a.m_row[1].w = 0.f;\n"
"	a.m_row[2].w = 0.f;\n"
"	for(int i=0; i<3; i++)\n"
"	{\n"
"//	a.m_row[i].w = 0.f;\n"
"		ans.m_row[i].x = dot3F4(a.m_row[i],transB.m_row[0]);\n"
"		ans.m_row[i].y = dot3F4(a.m_row[i],transB.m_row[1]);\n"
"		ans.m_row[i].z = dot3F4(a.m_row[i],transB.m_row[2]);\n"
"		ans.m_row[i].w = 0.f;\n"
"	}\n"
"	return ans;\n"
"}\n"
"__inline\n"
"float4 mtMul1(Matrix3x3 a, float4 b)\n"
"{\n"
"	float4 ans;\n"
"	ans.x = dot3F4( a.m_row[0], b );\n"
"	ans.y = dot3F4( a.m_row[1], b );\n"
"	ans.z = dot3F4( a.m_row[2], b );\n"
"	ans.w = 0.f;\n"
"	return ans;\n"
"}\n"
"__inline\n"
"float4 mtMul3(float4 a, Matrix3x3 b)\n"
"{\n"
"	float4 colx = make_float4(b.m_row[0].x, b.m_row[1].x, b.m_row[2].x, 0);\n"
"	float4 coly = make_float4(b.m_row[0].y, b.m_row[1].y, b.m_row[2].y, 0);\n"
"	float4 colz = make_float4(b.m_row[0].z, b.m_row[1].z, b.m_row[2].z, 0);\n"
"	float4 ans;\n"
"	ans.x = dot3F4( a, colx );\n"
"	ans.y = dot3F4( a, coly );\n"
"	ans.z = dot3F4( a, colz );\n"
"	return ans;\n"
"}\n"
"///////////////////////////////////////\n"
"//	Quaternion\n"
"///////////////////////////////////////\n"
"typedef float4 Quaternion;\n"
"__inline\n"
"Quaternion qtMul(Quaternion a, Quaternion b);\n"
"__inline\n"
"Quaternion qtNormalize(Quaternion in);\n"
"__inline\n"
"float4 qtRotate(Quaternion q, float4 vec);\n"
"__inline\n"
"Quaternion qtInvert(Quaternion q);\n"
"__inline\n"
"Quaternion qtMul(Quaternion a, Quaternion b)\n"
"{\n"
"	Quaternion ans;\n"
"	ans = cross3( a, b );\n"
"	ans += a.w*b+b.w*a;\n"
"//	ans.w = a.w*b.w - (a.x*b.x+a.y*b.y+a.z*b.z);\n"
"	ans.w = a.w*b.w - dot3F4(a, b);\n"
"	return ans;\n"
"}\n"
"__inline\n"
"Quaternion qtNormalize(Quaternion in)\n"
"{\n"
"	return fastNormalize4(in);\n"
"//	in /= length( in );\n"
"//	return in;\n"
"}\n"
"__inline\n"
"float4 qtRotate(Quaternion q, float4 vec)\n"
"{\n"
"	Quaternion qInv = qtInvert( q );\n"
"	float4 vcpy = vec;\n"
"	vcpy.w = 0.f;\n"
"	float4 out = qtMul(qtMul(q,vcpy),qInv);\n"
"	return out;\n"
"}\n"
"__inline\n"
"Quaternion qtInvert(Quaternion q)\n"
"{\n"
"	return (Quaternion)(-q.xyz, q.w);\n"
"}\n"
"__inline\n"
"float4 qtInvRotate(const Quaternion q, float4 vec)\n"
"{\n"
"	return qtRotate( qtInvert( q ), vec );\n"
"}\n"
"#define WG_SIZE 64\n"
"typedef struct\n"
"{\n"
"	float4 m_pos;\n"
"	Quaternion m_quat;\n"
"	float4 m_linVel;\n"
"	float4 m_angVel;\n"
"	u32 m_shapeIdx;\n"
"	float m_invMass;\n"
"	float m_restituitionCoeff;\n"
"	float m_frictionCoeff;\n"
"} Body;\n"
"typedef struct\n"
"{\n"
"	Matrix3x3 m_invInertia;\n"
"	Matrix3x3 m_initInvInertia;\n"
"} Shape;\n"
"typedef struct\n"
"{\n"
"	float4 m_linear;\n"
"	float4 m_worldPos[4];\n"
"	float4 m_center;	\n"
"	float m_jacCoeffInv[4];\n"
"	float m_b[4];\n"
"	float m_appliedRambdaDt[4];\n"
"	float m_fJacCoeffInv[2];	\n"
"	float m_fAppliedRambdaDt[2];	\n"
"	u32 m_bodyA;\n"
"	u32 m_bodyB;\n"
"	int m_batchIdx;\n"
"	u32 m_paddings[1];\n"
"} Constraint4;\n"
"typedef struct\n"
"{\n"
"	int m_nConstraints;\n"
"	int m_start;\n"
"	int m_batchIdx;\n"
"	int m_nSplit;\n"
"//	int m_paddings[1];\n"
"} ConstBuffer;\n"
"typedef struct\n"
"{\n"
"	int m_solveFriction;\n"
"	int m_maxBatch;	//	long batch really kills the performance\n"
"	int m_batchIdx;\n"
"	int m_nSplit;\n"
"//	int m_paddings[1];\n"
"} ConstBufferBatchSolve;\n"
" \n"
"typedef struct \n"
"{\n"
"	int m_valInt0;\n"
"	int m_valInt1;\n"
"	int m_valInt2;\n"
"	int m_valInt3;\n"
"	float m_val0;\n"
"	float m_val1;\n"
"	float m_val2;\n"
"	float m_val3;\n"
"} SolverDebugInfo;\n"
"//	others\n"
"__kernel\n"
"__attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void ReorderContactKernel(__global struct b3Contact4Data* in, __global struct b3Contact4Data* out, __global int2* sortData, int4 cb )\n"
"{\n"
"	int nContacts = cb.x;\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	if( gIdx < nContacts )\n"
"	{\n"
"		int srcIdx = sortData[gIdx].y;\n"
"		out[gIdx] = in[srcIdx];\n"
"	}\n"
"}\n"
"__kernel __attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void SetDeterminismSortDataChildShapeB(__global struct b3Contact4Data* contactsIn, __global int2* sortDataOut, int nContacts)\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	if( gIdx < nContacts )\n"
"	{\n"
"		int2 sd;\n"
"		sd.x = contactsIn[gIdx].m_childIndexB;\n"
"		sd.y = gIdx;\n"
"		sortDataOut[gIdx] = sd;\n"
"	}\n"
"}\n"
"__kernel __attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void SetDeterminismSortDataChildShapeA(__global struct b3Contact4Data* contactsIn, __global int2* sortDataInOut, int nContacts)\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	if( gIdx < nContacts )\n"
"	{\n"
"		int2 sdIn;\n"
"		sdIn = sortDataInOut[gIdx];\n"
"		int2 sdOut;\n"
"		sdOut.x = contactsIn[sdIn.y].m_childIndexA;\n"
"		sdOut.y = sdIn.y;\n"
"		sortDataInOut[gIdx] = sdOut;\n"
"	}\n"
"}\n"
"__kernel __attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void SetDeterminismSortDataBodyA(__global struct b3Contact4Data* contactsIn, __global int2* sortDataInOut, int nContacts)\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	if( gIdx < nContacts )\n"
"	{\n"
"		int2 sdIn;\n"
"		sdIn = sortDataInOut[gIdx];\n"
"		int2 sdOut;\n"
"		sdOut.x = contactsIn[sdIn.y].m_bodyAPtrAndSignBit;\n"
"		sdOut.y = sdIn.y;\n"
"		sortDataInOut[gIdx] = sdOut;\n"
"	}\n"
"}\n"
"__kernel\n"
"__attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void SetDeterminismSortDataBodyB(__global struct b3Contact4Data* contactsIn, __global int2* sortDataInOut, int nContacts)\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	if( gIdx < nContacts )\n"
"	{\n"
"		int2 sdIn;\n"
"		sdIn = sortDataInOut[gIdx];\n"
"		int2 sdOut;\n"
"		sdOut.x = contactsIn[sdIn.y].m_bodyBPtrAndSignBit;\n"
"		sdOut.y = sdIn.y;\n"
"		sortDataInOut[gIdx] = sdOut;\n"
"	}\n"
"}\n"
"typedef struct\n"
"{\n"
"	int m_nContacts;\n"
"	int m_staticIdx;\n"
"	float m_scale;\n"
"	int m_nSplit;\n"
"} ConstBufferSSD;\n"
"static __constant const int gridTable4x4[] = \n"
"{\n"
"    0,1,17,16,\n"
"	1,2,18,19,\n"
"	17,18,32,3,\n"
"	16,19,3,34\n"
"};\n"
"static __constant const int gridTable8x8[] = \n"
"{\n"
"	  0,  2,  3, 16, 17, 18, 19,  1,\n"
"	 66, 64, 80, 67, 82, 81, 65, 83,\n"
"	131,144,128,130,147,129,145,146,\n"
"	208,195,194,192,193,211,210,209,\n"
"	 21, 22, 23,  5,  4,  6,  7, 20,\n"
"	 86, 85, 69, 87, 70, 68, 84, 71,\n"
"	151,133,149,150,135,148,132,134,\n"
"	197,27,214,213,212,199,198,196\n"
"	\n"
"};\n"
"#define USE_SPATIAL_BATCHING 1\n"
"#define USE_4x4_GRID 1\n"
"__kernel\n"
"__attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void SetSortDataKernel(__global struct b3Contact4Data* gContact, __global Body* gBodies, __global int2* gSortDataOut, \n"
"int nContacts,float scale,int4 nSplit,int staticIdx)\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	\n"
"	if( gIdx < nContacts )\n"
"	{\n"
"		int aPtrAndSignBit  = gContact[gIdx].m_bodyAPtrAndSignBit;\n"
"		int bPtrAndSignBit  = gContact[gIdx].m_bodyBPtrAndSignBit;\n"
"		int aIdx = abs(aPtrAndSignBit );\n"
"		int bIdx = abs(bPtrAndSignBit);\n"
"		bool aStatic = (aPtrAndSignBit<0) ||(aPtrAndSignBit==staticIdx);\n"
"		bool bStatic = (bPtrAndSignBit<0) ||(bPtrAndSignBit==staticIdx);\n"
"#if USE_SPATIAL_BATCHING		\n"
"		int idx = (aStatic)? bIdx: aIdx;\n"
"		float4 p = gBodies[idx].m_pos;\n"
"		int xIdx = (int)((p.x-((p.x<0.f)?1.f:0.f))*scale) & (nSplit.x-1);\n"
"		int yIdx = (int)((p.y-((p.y<0.f)?1.f:0.f))*scale) & (nSplit.y-1);\n"
"		int zIdx = (int)((p.z-((p.z<0.f)?1.f:0.f))*scale) & (nSplit.z-1);\n"
"		int newIndex = (xIdx+yIdx*nSplit.x+zIdx*nSplit.x*nSplit.y);\n"
"		\n"
"#else//USE_SPATIAL_BATCHING\n"
"	#if USE_4x4_GRID\n"
"		int aa = aIdx&3;\n"
"		int bb = bIdx&3;\n"
"		if (aStatic)\n"
"			aa = bb;\n"
"		if (bStatic)\n"
"			bb = aa;\n"
"		int gridIndex = aa + bb*4;\n"
"		int newIndex = gridTable4x4[gridIndex];\n"
"	#else//USE_4x4_GRID\n"
"		int aa = aIdx&7;\n"
"		int bb = bIdx&7;\n"
"		if (aStatic)\n"
"			aa = bb;\n"
"		if (bStatic)\n"
"			bb = aa;\n"
"		int gridIndex = aa + bb*8;\n"
"		int newIndex = gridTable8x8[gridIndex];\n"
"	#endif//USE_4x4_GRID\n"
"#endif//USE_SPATIAL_BATCHING\n"
"		gSortDataOut[gIdx].x = newIndex;\n"
"		gSortDataOut[gIdx].y = gIdx;\n"
"	}\n"
"	else\n"
"	{\n"
"		gSortDataOut[gIdx].x = 0xffffffff;\n"
"	}\n"
"}\n"
"__kernel\n"
"__attribute__((reqd_work_group_size(WG_SIZE,1,1)))\n"
"void CopyConstraintKernel(__global struct b3Contact4Data* gIn, __global struct b3Contact4Data* gOut, int4 cb )\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"	if( gIdx < cb.x )\n"
"	{\n"
"		gOut[gIdx] = gIn[gIdx];\n"
"	}\n"
"}\n"
;
