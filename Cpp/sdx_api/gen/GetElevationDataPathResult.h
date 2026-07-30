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
    /// Result of GetElevationDataPath.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------
    /// Path string Path to the elevation data.
    ///

    class GetElevationDataPathResult;
    typedef std::shared_ptr<GetElevationDataPathResult> GetElevationDataPathResultPtr;
    
    
    class GetElevationDataPathResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetElevationDataPathResult();

      GetElevationDataPathResult(const std::string& path);

      GetElevationDataPathResult(CommandBasePtr relatedCommand, const std::string& path);

      static GetElevationDataPathResultPtr create(const std::string& path);

      static GetElevationDataPathResultPtr create(CommandBasePtr relatedCommand, const std::string& path);
      static GetElevationDataPathResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationDataPathResult);
  }
}

