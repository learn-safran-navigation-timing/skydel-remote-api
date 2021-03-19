#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsGalileoSatMotionFixed
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------------------------------
    /// Prn     int  Satellite PRN number
    /// IsFixed bool If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class IsGalileoSatMotionFixedResult;
    typedef std::shared_ptr<IsGalileoSatMotionFixedResult> IsGalileoSatMotionFixedResultPtr;
    
    
    class IsGalileoSatMotionFixedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsGalileoSatMotionFixedResult();

      IsGalileoSatMotionFixedResult(CommandBasePtr relatedCommand, int prn, bool isFixed);
  
      static IsGalileoSatMotionFixedResultPtr create(CommandBasePtr relatedCommand, int prn, bool isFixed);
      static IsGalileoSatMotionFixedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** isFixed ****
      bool isFixed() const;
      void setIsFixed(bool isFixed);
    };
  }
}

