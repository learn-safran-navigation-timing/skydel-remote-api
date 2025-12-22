#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasMessageUpdateInterval.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Message         int             The message type.
    /// UpdateInterval  int             The message update interval in seconds. Accepted range is [1..300].
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class GetSbasMessageUpdateIntervalResult;
    typedef std::shared_ptr<GetSbasMessageUpdateIntervalResult> GetSbasMessageUpdateIntervalResultPtr;
    
    
    class GetSbasMessageUpdateIntervalResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasMessageUpdateIntervalResult();

      GetSbasMessageUpdateIntervalResult(int message, int updateInterval, const std::optional<std::string>& serviceProvider = {});

      GetSbasMessageUpdateIntervalResult(CommandBasePtr relatedCommand, int message, int updateInterval, const std::optional<std::string>& serviceProvider = {});

      static GetSbasMessageUpdateIntervalResultPtr create(int message, int updateInterval, const std::optional<std::string>& serviceProvider = {});

      static GetSbasMessageUpdateIntervalResultPtr create(CommandBasePtr relatedCommand, int message, int updateInterval, const std::optional<std::string>& serviceProvider = {});
      static GetSbasMessageUpdateIntervalResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** message ****
      int message() const;
      void setMessage(int message);


      // **** updateInterval ****
      int updateInterval() const;
      void setUpdateInterval(int updateInterval);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMessageUpdateIntervalResult);
  }
}

