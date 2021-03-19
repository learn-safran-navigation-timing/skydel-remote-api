#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouSatelliteHealthStatus is deprecated since 21.3. You may use BeiDouHealthStatusForSV.
    /// 
    /// Set BeiDou satellite health status
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health int  Health Info, 2-bit integer : 0, 1, 2 or 3
    ///

    class SetBeiDouSatelliteHealthStatus;
    typedef std::shared_ptr<SetBeiDouSatelliteHealthStatus> SetBeiDouSatelliteHealthStatusPtr;
    
    
    class SetBeiDouSatelliteHealthStatus : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouSatelliteHealthStatus();

      SetBeiDouSatelliteHealthStatus(int prn, int health);
  
      static SetBeiDouSatelliteHealthStatusPtr create(int prn, int health);
      static SetBeiDouSatelliteHealthStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

