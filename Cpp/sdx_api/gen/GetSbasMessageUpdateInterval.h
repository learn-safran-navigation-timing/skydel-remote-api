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
    /// Get the SBAS message update interval.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Message         int             The message type.
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class GetSbasMessageUpdateInterval;
    typedef std::shared_ptr<GetSbasMessageUpdateInterval> GetSbasMessageUpdateIntervalPtr;
    
    
    class GetSbasMessageUpdateInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasMessageUpdateInterval();

      GetSbasMessageUpdateInterval(int message, const std::optional<std::string>& serviceProvider = {});

      static GetSbasMessageUpdateIntervalPtr create(int message, const std::optional<std::string>& serviceProvider = {});
      static GetSbasMessageUpdateIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** message ****
      int message() const;
      void setMessage(int message);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

