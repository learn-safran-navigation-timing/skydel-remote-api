#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS L1 health (Health of L1C/A signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssL1HealthForSV;
    typedef std::shared_ptr<GetQzssL1HealthForSV> GetQzssL1HealthForSVPtr;
    
    
    class GetQzssL1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1HealthForSV();

      GetQzssL1HealthForSV(int svId);
  
      static GetQzssL1HealthForSVPtr create(int svId);
      static GetQzssL1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

