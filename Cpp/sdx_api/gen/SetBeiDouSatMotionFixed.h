#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetBeiDouSatMotionFixed is deprecated since 21.3. You may use SetSatMotionFixed.
    /// 
    /// If IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------------------------------
    /// Prn     int  Satellite PRN number
    /// IsFixed bool If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class SetBeiDouSatMotionFixed;
    typedef std::shared_ptr<SetBeiDouSatMotionFixed> SetBeiDouSatMotionFixedPtr;
    
    
    class SetBeiDouSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouSatMotionFixed();

      SetBeiDouSatMotionFixed(int prn, bool isFixed);
  
      static SetBeiDouSatMotionFixedPtr create(int prn, bool isFixed);
      static SetBeiDouSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** isFixed ****
      bool isFixed() const;
      void setIsFixed(bool isFixed);
    };
  }
}

