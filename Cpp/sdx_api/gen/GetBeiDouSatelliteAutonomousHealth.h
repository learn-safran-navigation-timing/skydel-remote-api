#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouSatelliteAutonomousHealth is deprecated since 21.3. You may use BeiDouAutonomousHealthForSV.
    /// 
    /// Get BeiDou satellite autonomous health
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouSatelliteAutonomousHealth;
    typedef std::shared_ptr<GetBeiDouSatelliteAutonomousHealth> GetBeiDouSatelliteAutonomousHealthPtr;
    
    
    class GetBeiDouSatelliteAutonomousHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouSatelliteAutonomousHealth();

      GetBeiDouSatelliteAutonomousHealth(int prn);
  
      static GetBeiDouSatelliteAutonomousHealthPtr create(int prn);
      static GetBeiDouSatelliteAutonomousHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

