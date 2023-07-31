module; // �۷ι� ��� �÷��׸�Ʈ ���� �ȿ����� include ����.
#include <vector>
export module aptoCore.rawData.RawKeyFrameData;

import apto.math.Quaternion;
import apto.math.Vector3f;

export namespace aptoCore
{
	struct RawKeyFrameData
	{
		RawKeyFrameData() :
			pos(),
			rot()
		{

		}

		// frame, pos
		std::vector<std::pair<float, apto::Vector3f>> pos;
		// frame, rot
		std::vector<std::pair<float, apto::Quaternion>> rot;
	};
}
