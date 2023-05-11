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
    /// Result of GetAlmanacUploadTimeInterval.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------
    /// System   string Must be "GPS"
    /// Interval int    Interval duration in sec. Accepted range is [3600..259200]
    ///

    class GetAlmanacUploadTimeIntervalResult;
    typedef std::shared_ptr<GetAlmanacUploadTimeIntervalResult> GetAlmanacUploadTimeIntervalResultPtr;
    
    
    class GetAlmanacUploadTimeIntervalResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAlmanacUploadTimeIntervalResult();

      GetAlmanacUploadTimeIntervalResult(const std::string& system, int interval);

      GetAlmanacUploadTimeIntervalResult(CommandBasePtr relatedCommand, const std::string& system, int interval);

      static GetAlmanacUploadTimeIntervalResultPtr create(const std::string& system, int interval);

      static GetAlmanacUploadTimeIntervalResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int interval);
      static GetAlmanacUploadTimeIntervalResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** interval ****
      int interval() const;
      void setInterval(int interval);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAlmanacUploadTimeIntervalResult);
  }
}

