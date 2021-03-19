#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS L2 health (Health of L2C signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L2 health, false = signal OK, true = signal bad
    ///

    class SetQzssL2HealthForSV;
    typedef std::shared_ptr<SetQzssL2HealthForSV> SetQzssL2HealthForSVPtr;
    
    
    class SetQzssL2HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssL2HealthForSV();

      SetQzssL2HealthForSV(int svId, bool health);
  
      static SetQzssL2HealthForSVPtr create(int svId, bool health);
      static SetQzssL2HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

