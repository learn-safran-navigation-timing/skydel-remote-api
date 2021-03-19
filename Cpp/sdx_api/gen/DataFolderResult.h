#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of the command "GetDataFolder"
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------
    /// Folder string Skydel Data Folder
    ///

    class DataFolderResult;
    typedef std::shared_ptr<DataFolderResult> DataFolderResultPtr;
    
    
    class DataFolderResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      DataFolderResult();

      DataFolderResult(CommandBasePtr relatedCommand, const std::string& folder);
  
      static DataFolderResultPtr create(CommandBasePtr relatedCommand, const std::string& folder);
      static DataFolderResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** folder ****
      std::string folder() const;
      void setFolder(const std::string& folder);
    };
  }
}

