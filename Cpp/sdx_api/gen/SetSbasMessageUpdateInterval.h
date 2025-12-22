#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the SBAS message update interval.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Message         int             The message type.
    /// UpdateInterval  int             The message update interval in seconds. Accepted range is [1..300].
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class SetSbasMessageUpdateInterval;
    typedef std::shared_ptr<SetSbasMessageUpdateInterval> SetSbasMessageUpdateIntervalPtr;
    
    
    class SetSbasMessageUpdateInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasMessageUpdateInterval();

      SetSbasMessageUpdateInterval(int message, int updateInterval, const std::optional<std::string>& serviceProvider = {});

      static SetSbasMessageUpdateIntervalPtr create(int message, int updateInterval, const std::optional<std::string>& serviceProvider = {});
      static SetSbasMessageUpdateIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

