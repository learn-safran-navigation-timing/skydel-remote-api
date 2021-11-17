#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetBeiDouSatelliteAutonomousHealth is deprecated since 21.3. You may use SetBeiDouAutonomousHealthForSV.
    /// 
    /// Set BeiDou satellite autonomous health
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health bool Status, false = Good, true = Not Good
    ///

    class SetBeiDouSatelliteAutonomousHealth;
    typedef std::shared_ptr<SetBeiDouSatelliteAutonomousHealth> SetBeiDouSatelliteAutonomousHealthPtr;
    
    
    class SetBeiDouSatelliteAutonomousHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouSatelliteAutonomousHealth();

      SetBeiDouSatelliteAutonomousHealth(int prn, bool health);
  
      static SetBeiDouSatelliteAutonomousHealthPtr create(int prn, bool health);
      static SetBeiDouSatelliteAutonomousHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

