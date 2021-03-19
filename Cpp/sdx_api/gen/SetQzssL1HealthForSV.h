#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS L1 health (Health of L1C/A signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L1 health, false = signal OK, true = signal bad
    ///

    class SetQzssL1HealthForSV;
    typedef std::shared_ptr<SetQzssL1HealthForSV> SetQzssL1HealthForSVPtr;
    
    
    class SetQzssL1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssL1HealthForSV();

      SetQzssL1HealthForSV(int svId, bool health);
  
      static SetQzssL1HealthForSVPtr create(int svId, bool health);
      static SetQzssL1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

