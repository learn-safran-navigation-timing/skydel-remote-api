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
    /// Result of GetSbasServiceProviderForSV.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------------
    /// SvId            int    The satellite's SV ID.
    /// ServiceProvider string Service provider value, accepts "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM" and "SBAS".
    ///

    class GetSbasServiceProviderForSVResult;
    typedef std::shared_ptr<GetSbasServiceProviderForSVResult> GetSbasServiceProviderForSVResultPtr;
    
    
    class GetSbasServiceProviderForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasServiceProviderForSVResult();

      GetSbasServiceProviderForSVResult(int svId, const std::string& serviceProvider);

      GetSbasServiceProviderForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& serviceProvider);

      static GetSbasServiceProviderForSVResultPtr create(int svId, const std::string& serviceProvider);

      static GetSbasServiceProviderForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& serviceProvider);
      static GetSbasServiceProviderForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasServiceProviderForSVResult);
  }
}

