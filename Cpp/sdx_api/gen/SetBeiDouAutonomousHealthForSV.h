#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou satellite autonomous health
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health bool Status, false = Good, true = Not Good
    ///

    class SetBeiDouAutonomousHealthForSV;
    typedef std::shared_ptr<SetBeiDouAutonomousHealthForSV> SetBeiDouAutonomousHealthForSVPtr;
    
    
    class SetBeiDouAutonomousHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouAutonomousHealthForSV();

      SetBeiDouAutonomousHealthForSV(int svId, bool health);
  
      static SetBeiDouAutonomousHealthForSVPtr create(int svId, bool health);
      static SetBeiDouAutonomousHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

