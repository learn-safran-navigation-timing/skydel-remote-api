#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS L2 health (Health of L2C signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssL2HealthForSV;
    typedef std::shared_ptr<GetQzssL2HealthForSV> GetQzssL2HealthForSVPtr;
    
    
    class GetQzssL2HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL2HealthForSV();

      GetQzssL2HealthForSV(int svId);
  
      static GetQzssL2HealthForSVPtr create(int svId);
      static GetQzssL2HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

