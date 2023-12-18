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
    /// Result of GetEphemerisUpdateInterval.
    ///
    /// Name     Type   Description
    /// -------- ------ -----------------------------------------------------------------------------------------------------------------------
    /// System   string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds in a week (604800).
    ///

    class GetEphemerisUpdateIntervalResult;
    typedef std::shared_ptr<GetEphemerisUpdateIntervalResult> GetEphemerisUpdateIntervalResultPtr;
    
    
    class GetEphemerisUpdateIntervalResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEphemerisUpdateIntervalResult();

      GetEphemerisUpdateIntervalResult(const std::string& system, int interval);

      GetEphemerisUpdateIntervalResult(CommandBasePtr relatedCommand, const std::string& system, int interval);

      static GetEphemerisUpdateIntervalResultPtr create(const std::string& system, int interval);

      static GetEphemerisUpdateIntervalResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int interval);
      static GetEphemerisUpdateIntervalResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** interval ****
      int interval() const;
      void setInterval(int interval);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetEphemerisUpdateIntervalResult);
  }
}

