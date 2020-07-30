//==================================================================================================================
//
// ���U���g���� [ result.cpp ]
// Author : KANAN NAGANAWA
//
//==================================================================================================================
#include "inputKeyboard.h"
#include "renderer.h"
#include "result.h"
#include "number.h"
#include "fade.h"
#include "sound.h"
#include "inputGamepad.h"

//==================================================================================================================
//�}�N���I�U
//==================================================================================================================
#define RANKING_COUNT_MAX 600			// �����L���O�J�E���g�̍ő吔
#define	TIME_COUNT (600)				// �����t�F�[�h����J�E���^

//==================================================================================================================
// �ÓI�����o�[�ϐ��̏�����
//==================================================================================================================
int CResult::m_nTime = NULL;					// �^�C���ϐ�

//==================================================================================================================
//
// �R���X�g���N�^
//
//==================================================================================================================
CResult::CResult()
{

}

//==================================================================================================================
//
// �f�X�g���N�^
//
//==================================================================================================================
CResult::~CResult()
{

}

//==================================================================================================================
// ������
//==================================================================================================================
void CResult::Init(void)
{
	// �ϐ��̏�����
	//m_nCntTitle = 0;										// �^�C�g���ւ̃J�E���^
	//
	//// ������
	//m_nTime = 0;											// �^�C��
}

//==================================================================================================================
// �I��
//==================================================================================================================
void CResult::Uninit(void)
{
	// Scene2D�S�폜
	CScene2D::ReleaseAll();
}

//==================================================================================================================
// �X�V
//==================================================================================================================
void CResult::Update(void)
{
	// �L�[�{�[�h�擾
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// �t�F�[�h�擾
	CFade::FADE Fade = CFade::GetFade();

	// ���擾
	CSound *pSound = CRenderer::GetSound();

	// �^�C�����Z
	m_nTime++;

	// �L�[�{�[�h��[Enter]�������ꂽ�Ƃ� ���� �^�C���J�E���g��MAX������ ���� �R���g���[���[��[START]�������ꂽ�Ƃ�
	if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || m_nTime > TIME_COUNT)
	{
		// �t�F�[�h��Ԃ��Ȃ���
		if (Fade == CFade::FADE_NONE)
		{
			CFade::SetFade(CRenderer::MODE_TITLE, DEFAULT_FADE_TIME);					// �t�F�[�h�̐ݒ�
		}
	}

	// �^�C�g���ւ̃J�E���^���Z
	m_nCntTitle++;

	// �����L���O�J�E���^���K��l�𒴂�����
	if (m_nCntTitle >= RANKING_COUNT_MAX)
	{
		// �t�F�[�h�������Ȃ���
		if (Fade == CFade::FADE_NONE)
		{
			// �t�F�[�h�̐ݒ�
			CFade::SetFade(CRenderer::MODE_TITLE, DEFAULT_FADE_TIME);
		}
	}
}

//==================================================================================================================
// �`�揈��
//==================================================================================================================
void CResult::Draw(void)
{

}

//==================================================================================================================
// ����
//==================================================================================================================
CResult *CResult::Create(void)
{
	// �������m��
	CResult *pResult = new CResult;
	// ������
	pResult->Init();
	// �l��Ԃ�
	return pResult;
}