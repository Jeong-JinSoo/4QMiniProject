module;
#include <vector>
#include <string>
export module aptoCore.rawData.RawNode;

import apto.Transform;
import apto.math.Matrix4f;
import aptoCore.rawData.RawKeyFrameData;

export namespace aptoCore
{
	struct RawNode
	{
		std::string name;
		apto::Transform transform;
		apto::Matrix4f worldMatrix;

		RawNode* parent;
		std::vector<RawNode*> children;

		bool isSkinnedNode;

		// ���� bone�� �ƴ϶�� �ε��� ���� -1
		// bone�̶�� 0 �̻�
		int boneIndex;

		// ��庰 �ִϸ��̼��� ���� ������.
		RawKeyFrameData keyFrameData;
	};
}