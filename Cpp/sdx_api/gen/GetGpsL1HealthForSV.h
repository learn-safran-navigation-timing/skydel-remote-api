#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS L1 health (used with CNAV and CNAV2)
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsL1HealthForSV;
    typedef std::shared_ptr<GetGpsL1HealthForSV> GetGpsL1HealthForSVPtr;
    
    
    class GetGpsL1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL1HealthForSV();

      GetGpsL1HealthForSV(int svId);
  
      static GetGpsL1HealthForSVPtr create(int svId);
      static GetGpsL1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

