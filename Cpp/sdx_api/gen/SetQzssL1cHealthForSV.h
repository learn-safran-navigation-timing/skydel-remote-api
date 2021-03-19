#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS L1C health (Health of L1C signal)
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------
    /// SvId   int  Satellite SV ID 1..10
    /// Health bool L1C health, false = signal OK, true = signal bad
    ///

    class SetQzssL1cHealthForSV;
    typedef std::shared_ptr<SetQzssL1cHealthForSV> SetQzssL1cHealthForSVPtr;
    
    
    class SetQzssL1cHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssL1cHealthForSV();

      SetQzssL1cHealthForSV(int svId, bool health);
  
      static SetQzssL1cHealthForSVPtr create(int svId, bool health);
      static SetQzssL1cHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

