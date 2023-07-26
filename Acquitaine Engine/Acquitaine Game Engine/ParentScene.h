#pragma once
#include <vector>

#include "IObject.h"

using namespace std;

class ParentScene
{
public:
	ParentScene();
	~ParentScene();

public:
	void AddObject();
	void RemoveObject();
	void ChangeObjectState();

private:
	vector<IObject*>  inControlObjects;
};

/// Scene ����
//  ���� ������Ʈ���� �� Scene�� ���ӿ�����Ʈ�� ������ ������ �и��Ǿ� ���� SceneManager�� ���� ���� ���ư��� ���� ������
//  �̹��� Scene�� �и��ؼ� Scene�� ��ũ���� �������� ��ƺ����� �Ѵ�.
//  Scene�� CreateObject �Լ��� �ּ� ������Ʈ�� �����ϰ�
//  ������ ������Ʈ�� Scene�� inControlObjects�� ������ ObjectList�� �߰���
//  ��... Scene�� inControlObjects���� ������Ʈ���� �����Ѵ�.(������ ������ ��û�ϴ°�����)
//  �ϴ��� Scene�� ������Ʈ�� ��Ƶΰ� �����ϴ� �߰� �ܰ�� ����.
//  ��¶�� ������ ¥�� ���ӿ����� �ǵ� �� ���� �ϴ°� ��ǥ.