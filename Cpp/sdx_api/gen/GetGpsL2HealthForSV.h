#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS L2 health (used with CNAV and CNAV2)
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsL2HealthForSV;
    typedef std::shared_ptr<GetGpsL2HealthForSV> GetGpsL2HealthForSVPtr;
    
    
    class GetGpsL2HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL2HealthForSV();

      GetGpsL2HealthForSV(int svId);
  
      static GetGpsL2HealthForSVPtr create(int svId);
      static GetGpsL2HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

