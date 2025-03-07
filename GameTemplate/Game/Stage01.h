#pragma once
class Stage01 : public IGameObject
{
public:
	Stage01();
	~Stage01();
	//スタート
	bool Start();
	//アップデート
	void Update();
	//レンダー
	void Render(RenderContext& rc);
	/// 座標を設定する。
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	/// 大きさを設定する。
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}
	/// 回転を設定する。
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}


	ModelRender					m_modelRender;					//モデルレンダー。
	Vector3						m_position;						//座標。
	Vector3						m_scale = Vector3::One;			//大きさ。
	Quaternion					m_rotation;						//回転。


private:

	//回転処理
	void Rotation();

	
	PhysicsStaticObject			m_physicsStaticObject;
	Quaternion                  m_moveRotation;
	


};

