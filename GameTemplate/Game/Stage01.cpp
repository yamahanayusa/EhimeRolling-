#include "stdafx.h"
#include "Stage01.h"

Stage01::Stage01()
{

}

Stage01::~Stage01()
{

}

bool Stage01::Start()
{
	//モデルを読み込む。
	m_modelRender.Init("Assets/Stage01/stage.tkm");
	//座標を設定する
	m_modelRender.SetPosition(m_position);
	//大きさを設定する
	m_modelRender.SetScale(m_scale);
	//回転を設定する
	m_modelRender.SetRotation(m_rotation);
	//モデルを更新する
	m_modelRender.Update();
	//当たり判定を作成する。
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;

}


void Stage01::Update()
{
	//回転処理
	Rotation();

	//モデルの更新処理。
	m_modelRender.Update();
}

void Stage01::Rotation()
{
	m_moveRotation.a = 0.0f;//X軸　
	m_moveRotation.b = 0.0f;//Y軸
	m_moveRotation.g = 0.0f;//Z軸

	//左スティックの入力量を受け取る
	float lStick_x = g_pad[0]->GetLStickXF();
	float lStick_y = g_pad[0]->GetLStickYF();





}

void Stage01::Render(RenderContext& rc)
{
	//モデルを描画する
	m_modelRender.Draw(rc);
}