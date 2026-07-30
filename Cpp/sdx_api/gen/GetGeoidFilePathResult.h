#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGeoidFilePath.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Path string Path to the Geoid file to use.
    ///

    class GetGeoidFilePathResult;
    typedef std::shared_ptr<GetGeoidFilePathResult> GetGeoidFilePathResultPtr;
    
    
    class GetGeoidFilePathResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGeoidFilePathResult();

      GetGeoidFilePathResult(const std::string& path);

      GetGeoidFilePathResult(CommandBasePtr relatedCommand, const std::string& path);

      static GetGeoidFilePathResultPtr create(const std::string& path);

      static GetGeoidFilePathResultPtr create(CommandBasePtr relatedCommand, const std::string& path);
      static GetGeoidFilePathResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGeoidFilePathResult);
  }
}

