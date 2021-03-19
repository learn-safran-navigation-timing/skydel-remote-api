#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS L1C health (used in CNAV2 only)
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------------------------------------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health bool L1C health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsL1cHealthForSV;
    typedef std::shared_ptr<SetGpsL1cHealthForSV> SetGpsL1cHealthForSVPtr;
    
    
    class SetGpsL1cHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsL1cHealthForSV();

      SetGpsL1cHealthForSV(int svId, bool health);
  
      static SetGpsL1cHealthForSVPtr create(int svId, bool health);
      static SetGpsL1cHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

