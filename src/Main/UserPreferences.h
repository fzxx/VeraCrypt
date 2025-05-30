/*
 Derived from source code of TrueCrypt 7.1a, which is
 Copyright (c) 2008-2012 TrueCrypt Developers Association and which is governed
 by the TrueCrypt License 3.0.

 Modifications and additions to the original source code (contained in this file)
 and all other portions of this file are Copyright (c) 2013-2025 AM Crypto
 and are governed by the Apache License 2.0 the full text of which is
 contained in the file License.txt included in VeraCrypt binary and source
 code distribution packages.
*/

#ifndef TC_HEADER_Main_UserPreferences
#define TC_HEADER_Main_UserPreferences

#include "System.h"
#include "Main.h"
#include "Hotkey.h"

namespace VeraCrypt
{
	struct UserPreferences
	{
		UserPreferences ()
			:
			BackgroundTaskEnabled (true),
			BackgroundTaskMenuDismountItemsEnabled (true),
			BackgroundTaskMenuMountItemsEnabled (true),
			BackgroundTaskMenuOpenItemsEnabled (true),
			BeepAfterHotkeyMountDismount (false),
			CloseBackgroundTaskOnNoVolumes (true),
			CloseExplorerWindowsOnDismount (true),
			CloseSecurityTokenSessionsAfterMount (false),
			EMVSupportEnabled (false),
			DisableKernelEncryptionModeWarning (false),
			DismountOnInactivity (false),
			DismountOnLogOff (true),
			DismountOnPowerSaving (false),
			DismountOnScreenSaver (false),
			DisplayMessageAfterHotkeyDismount (false),
			ForceAutoDismount (true),
			Language (L"system"),
			LastSelectedSlotNumber (0),
			MaxVolumeIdleTime (60),
			MountDevicesOnLogon (false),
			MountFavoritesOnLogon (false),
			NonInteractive (false),
			UseStandardInput (false),
			OpenExplorerWindowAfterMount (false),
			SaveHistory (false),
			StartOnLogon (false),
			UseKeyfiles (false),
			Verbose (false),
			WipeCacheOnAutoDismount (true),
			WipeCacheOnClose (false)
		{
		}

		virtual ~UserPreferences ()
		{
		}
		void Load();
		void Save() const;

		HotkeyList Hotkeys;
		KeyfileList DefaultKeyfiles;
		MountOptions DefaultMountOptions;

		bool BackgroundTaskEnabled;
		bool BackgroundTaskMenuDismountItemsEnabled;
		bool BackgroundTaskMenuMountItemsEnabled;
		bool BackgroundTaskMenuOpenItemsEnabled;
		bool BeepAfterHotkeyMountDismount;
		bool CloseBackgroundTaskOnNoVolumes;
		bool CloseExplorerWindowsOnDismount;
		bool CloseSecurityTokenSessionsAfterMount;
        bool EMVSupportEnabled;
		bool DisableKernelEncryptionModeWarning;
		bool DismountOnInactivity;
		bool DismountOnLogOff;
		bool DismountOnPowerSaving;
		bool DismountOnScreenSaver;
		bool DisplayMessageAfterHotkeyDismount;
		bool ForceAutoDismount;
		wstring Language;
		uint64 LastSelectedSlotNumber;
		int32 MaxVolumeIdleTime;
		bool MountDevicesOnLogon;
		bool MountFavoritesOnLogon;
		bool NonInteractive;
		bool UseStandardInput;
		bool OpenExplorerWindowAfterMount;
		bool SaveHistory;
		FilePath SecurityTokenModule;
		bool StartOnLogon;
		bool UseKeyfiles;
		bool Verbose;
		bool WipeCacheOnAutoDismount;
		bool WipeCacheOnClose;

		// A map used to store unknown entries from the configuration file in order to preserve them when saving the configuration.
		// This helps to preserve unknown entries that may be used by future versions of VeraCrypt or entries used by old versions that were removed from current version.
		map <wxString, wxString> UnknownConfigMapEntries;

	protected:
		wxString GetDefaultKeyfilesFileName () const { return L"Default Keyfiles.xml"; }
#ifdef TC_PROTOTYPE
		wxString GetPreferencesFileName () const { return L"Configuration_Debug.xml"; }
#else
		wxString GetPreferencesFileName () const { return L"Configuration.xml"; }
#endif
		void SetValue (const wxString &cfgText, bool &cfgVar);
		void SetValue (const wxString &cfgText, int &cfgVar);
		void SetValue (const wxString &cfgText, uint64 &cfgVar);
		void SetValue (const wxString &cfgText, wstring &cfgVar);
		void SetValue (const wxString &cfgText, wxString &cfgVar);
		void SetValue (const wxString &cfgText, FilesystemPath &cfgVar);
	};
}

#endif // TC_HEADER_Main_UserPreferences
