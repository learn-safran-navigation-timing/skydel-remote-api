#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetStartTimeMode.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------------
    /// Mode string Accepted Modes ("Custom", "Computer", "GPS")
    ///

    class GetStartTimeModeResult;
    typedef std::shared_ptr<GetStartTimeModeResult> GetStartTimeModeResultPtr;
    
    
    class GetStartTimeModeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetStartTimeModeResult();

      GetStartTimeModeResult(const std::string& mode);

      GetStartTimeModeResult(CommandBasePtr relatedCommand, const std::string& mode);

      static GetStartTimeModeResultPtr create(const std::string& mode);

      static GetStartTimeModeResultPtr create(CommandBasePtr relatedCommand, const std::string& mode);
      static GetStartTimeModeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** mode ****
      std::string mode() const;
      void setMode(const std::string& mode);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetStartTimeModeResult);
  }
}

