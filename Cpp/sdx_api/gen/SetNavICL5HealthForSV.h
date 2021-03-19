#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set NavIC L5 health (Health of L5 signal)
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------
    /// SvId   int  Satellite SV ID 1..14
    /// Health bool L5 health, false = signal OK, true = signal bad
    ///

    class SetNavICL5HealthForSV;
    typedef std::shared_ptr<SetNavICL5HealthForSV> SetNavICL5HealthForSVPtr;
    
    
    class SetNavICL5HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICL5HealthForSV();

      SetNavICL5HealthForSV(int svId, bool health);
  
      static SetNavICL5HealthForSVPtr create(int svId, bool health);
      static SetNavICL5HealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

