#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Skydel's Data Folder. The user can changed it in the GUI's Preferences.
    ///
    /// 
    ///

    class GetDataFolder;
    typedef std::shared_ptr<GetDataFolder> GetDataFolderPtr;
    
    
    class GetDataFolder : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDataFolder();

      static GetDataFolderPtr create();
      static GetDataFolderPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

