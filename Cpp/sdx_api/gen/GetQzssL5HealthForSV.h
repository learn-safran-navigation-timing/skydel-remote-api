#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS L5 health (Health of L5 signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssL5HealthForSV;
    typedef std::shared_ptr<GetQzssL5HealthForSV> GetQzssL5HealthForSVPtr;
    
    
    class GetQzssL5HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL5HealthForSV();

      GetQzssL5HealthForSV(int svId);
  
      static GetQzssL5HealthForSVPtr create(int svId);
      static GetQzssL5HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

