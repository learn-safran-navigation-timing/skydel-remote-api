#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the service provider of the SBAS satellite.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------------
    /// SvId            int    The satellite's SV ID.
    /// ServiceProvider string Service provider value, accepts "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM" and "SBAS".
    ///

    class SetSbasServiceProviderForSV;
    typedef std::shared_ptr<SetSbasServiceProviderForSV> SetSbasServiceProviderForSVPtr;
    
    
    class SetSbasServiceProviderForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasServiceProviderForSV();

      SetSbasServiceProviderForSV(int svId, const std::string& serviceProvider);

      static SetSbasServiceProviderForSVPtr create(int svId, const std::string& serviceProvider);
      static SetSbasServiceProviderForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);
    };
    
  }
}

