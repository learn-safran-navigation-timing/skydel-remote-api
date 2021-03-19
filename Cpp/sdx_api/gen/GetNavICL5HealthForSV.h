#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get NavIC L5 health (Health of L5 signal)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..14
    ///

    class GetNavICL5HealthForSV;
    typedef std::shared_ptr<GetNavICL5HealthForSV> GetNavICL5HealthForSVPtr;
    
    
    class GetNavICL5HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICL5HealthForSV();

      GetNavICL5HealthForSV(int svId);
  
      static GetNavICL5HealthForSVPtr create(int svId);
      static GetNavICL5HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

