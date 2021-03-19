#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command QzssSatMotionFixed is deprecated since 20.9. You may use SatMotionFixed.
    /// 
    /// If IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------------------------------
    /// SvId    int  Satellite SV ID number
    /// IsFixed bool If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class SetQzssSatMotionFixed;
    typedef std::shared_ptr<SetQzssSatMotionFixed> SetQzssSatMotionFixedPtr;
    
    
    class SetQzssSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatMotionFixed();

      SetQzssSatMotionFixed(int svId, bool isFixed);
  
      static SetQzssSatMotionFixedPtr create(int svId, bool isFixed);
      static SetQzssSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** isFixed ****
      bool isFixed() const;
      void setIsFixed(bool isFixed);
    };
  }
}

