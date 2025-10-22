#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the service provider of the SBAS satellite.
    ///
    /// Name Type Description
    /// ---- ---- ----------------------
    /// SvId int  The satellite's SV ID.
    ///

    class GetSbasServiceProviderForSV;
    typedef std::shared_ptr<GetSbasServiceProviderForSV> GetSbasServiceProviderForSVPtr;
    
    
    class GetSbasServiceProviderForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasServiceProviderForSV();

      GetSbasServiceProviderForSV(int svId);

      static GetSbasServiceProviderForSVPtr create(int svId);
      static GetSbasServiceProviderForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

