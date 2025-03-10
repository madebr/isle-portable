#include "police.h"

#include "jukebox.h"
#include "jukebox_actions.h"
#include "legocontrolmanager.h"
#include "legogamestate.h"
#include "legoinputmanager.h"
#include "legomain.h"
#include "misc.h"
#include "mxactionnotificationparam.h"
#include "mxbackgroundaudiomanager.h"
#include "mxmisc.h"
#include "mxnotificationmanager.h"
#include "mxtransitionmanager.h"
#include "police_actions.h"
#include "scripts.h"

DECOMP_SIZE_ASSERT(Police, 0x110)
DECOMP_SIZE_ASSERT(PoliceState, 0x10)

// FUNCTION: LEGO1 0x1005e130
Police::Police()
{
	m_policeState = NULL;
	m_destLocation = LegoGameState::e_undefined;
	NotificationManager()->Register(this);
}

// FUNCTION: LEGO1 0x1005e1d0
MxBool Police::VTable0x5c()
{
	return TRUE;
}

// FUNCTION: LEGO1 0x1005e320
Police::~Police()
{
	if (InputManager()->GetWorld() == this) {
		InputManager()->ClearWorld();
	}

	ControlManager()->Unregister(this);
	InputManager()->UnRegister(this);
	NotificationManager()->Unregister(this);
}

// FUNCTION: LEGO1 0x1005e3e0
MxResult Police::Create(MxDSAction& p_dsAction)
{
	MxResult ret = LegoWorld::Create(p_dsAction);
	if (ret == SUCCESS) {
		InputManager()->SetWorld(this);
		ControlManager()->Register(this);
	}

	SetIsWorldActive(FALSE);
	InputManager()->Register(this);

	LegoGameState* gameState = GameState();
	PoliceState* policeState = (PoliceState*) gameState->GetState("PoliceState");
	if (!policeState) {
		policeState = (PoliceState*) gameState->CreateState("PoliceState");
	}

	m_policeState = policeState;
	GameState()->SetCurrentArea(LegoGameState::e_police);
	GameState()->StopArea(LegoGameState::e_previousArea);
	return ret;
}

// FUNCTION: LEGO1 0x1005e480
MxLong Police::Notify(MxParam& p_param)
{
	MxLong result = 0;
	LegoWorld::Notify(p_param);

	if (m_worldStarted) {
		switch (((MxNotificationParam&) p_param).GetNotification()) {
		case c_notificationEndAction:
			result = HandleEndAction((MxEndActionNotificationParam&) p_param);
			break;
		case c_notificationKeyPress:
			result = HandleKeyPress(((LegoEventNotificationParam&) p_param));
			break;
		case c_notificationControl:
			result = HandleControl((LegoControlManagerEvent&) p_param);
			break;
		case c_notificationTransitioned:
			GameState()->SwitchArea(m_destLocation);
			break;
		}
	}

	return result;
}

// FUNCTION: LEGO1 0x1005e530
void Police::ReadyWorld()
{
	LegoWorld::ReadyWorld();
	PlayMusic(JukeboxScript::c_PoliceStation_Music);
	FUN_10015820(FALSE, LegoOmni::c_disableInput | LegoOmni::c_disable3d | LegoOmni::c_clearScreen);
}

// FUNCTION: LEGO1 0x1005e550
MxLong Police::HandleControl(LegoControlManagerEvent& p_param)
{
	if (p_param.GetUnknown0x28() == 1) {
		switch (p_param.GetClickedObjectId()) {
		case PoliceScript::c_LeftArrow_Ctl:
		case PoliceScript::c_RightArrow_Ctl:
			if (m_policeState->GetUnknown0x0c() == 1) {
				DeleteObjects(&m_atom, PoliceScript::c_nps001ni_RunAnim, PoliceScript::c_nps002la_RunAnim);
			}

			BackgroundAudioManager()->Stop();
			m_destLocation = LegoGameState::Area::e_polidoor;
			TransitionManager()->StartTransition(MxTransitionManager::e_mosaic, 50, FALSE, FALSE);
			break;
		case PoliceScript::c_Info_Ctl:
			if (m_policeState->GetUnknown0x0c() == 1) {
				DeleteObjects(&m_atom, PoliceScript::c_nps001ni_RunAnim, PoliceScript::c_nps002la_RunAnim);
			}

			BackgroundAudioManager()->Stop();
			m_destLocation = LegoGameState::Area::e_infomain;
			TransitionManager()->StartTransition(MxTransitionManager::e_mosaic, 50, FALSE, FALSE);
			break;
		case PoliceScript::c_Door_Ctl:
			if (m_policeState->GetUnknown0x0c() == 1) {
				DeleteObjects(&m_atom, PoliceScript::c_nps001ni_RunAnim, PoliceScript::c_nps002la_RunAnim);
			}

			BackgroundAudioManager()->Stop();
			m_destLocation = LegoGameState::Area::e_copterbuild;
			TransitionManager()->StartTransition(MxTransitionManager::e_mosaic, 50, FALSE, FALSE);
			break;
		case PoliceScript::c_Donut_Ctl:
			m_policeState->FUN_1005ea40();
		}
	}

	return 1;
}

// FUNCTION: LEGO1 0x1005e6a0
MxLong Police::HandleEndAction(MxEndActionNotificationParam& p_param)
{
	MxDSAction* action = p_param.GetAction();

	if (m_radio.Notify(p_param) == 0 && m_atom == action->GetAtomId()) {
		if (m_policeState->GetUnknown0x0c() == 1) {
			m_policeState->SetUnknown0x0c(0);
			return 1;
		}

		return 0;
	}

	return 0;
}

// FUNCTION: LEGO1 0x1005e6f0
MxLong Police::HandleKeyPress(LegoEventNotificationParam& p_param)
{
	MxLong result = 0;

	if (p_param.GetKey() == VK_SPACE && m_policeState->GetUnknown0x0c() == 1) {
		DeleteObjects(&m_atom, PoliceScript::c_nps001ni_RunAnim, PoliceScript::c_nps002la_RunAnim);
		m_policeState->SetUnknown0x0c(0);
		return 1;
	}

	return 0;
}

// FUNCTION: LEGO1 0x1005e740
void Police::Enable(MxBool p_enable)
{
	LegoWorld::Enable(p_enable);

	if (p_enable) {
		InputManager()->SetWorld(this);
		SetIsWorldActive(FALSE);
	}
	else {
		if (InputManager()->GetWorld() == this) {
			InputManager()->ClearWorld();
		}
	}
}

// FUNCTION: LEGO1 0x1005e790
MxBool Police::Escape()
{
	DeleteObjects(&m_atom, PoliceScript::c_nps001ni_RunAnim, 510);
	m_destLocation = LegoGameState::e_infomain;
	return TRUE;
}

// FUNCTION: LEGO1 0x1005e7c0
PoliceState::PoliceState()
{
	m_unk0x0c = 0;
	m_policeScript = (rand() % 2 == 0) ? PoliceScript::c_nps002la_RunAnim : PoliceScript::c_nps001ni_RunAnim;
}

// FUNCTION: LEGO1 0x1005e990
MxResult PoliceState::Serialize(LegoFile* p_file)
{
	LegoState::Serialize(p_file);

	if (p_file->IsReadMode()) {
		Read(p_file, &m_policeScript);
	}
	else {
		Write(p_file, m_policeScript);
	}

	return SUCCESS;
}

// FUNCTION: LEGO1 0x1005ea40
void PoliceState::FUN_1005ea40()
{
	PoliceScript::Script policeScript;

	if (m_unk0x0c == 1) {
		return;
	}

	switch (UserActor()->GetActorId()) {
	case LegoActor::c_nick:
		policeScript = PoliceScript::c_nps002la_RunAnim;
		m_policeScript = policeScript;
		break;
	case LegoActor::c_laura:
		policeScript = PoliceScript::c_nps001ni_RunAnim;
		m_policeScript = policeScript;
		break;
	default:
		policeScript = m_policeScript;
		m_policeScript = policeScript == PoliceScript::c_nps002la_RunAnim ? PoliceScript::c_nps001ni_RunAnim
																		  : PoliceScript::c_nps002la_RunAnim;
	}

	{
		MxDSAction action;
		action.SetObjectId(policeScript);
		action.SetAtomId(*g_policeScript);
		Start(&action);
	}

	m_unk0x0c = 1;
}
