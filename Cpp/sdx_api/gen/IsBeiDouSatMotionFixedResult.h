#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsBeiDouSatMotionFixed.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------------------------------
    /// Prn     int  Satellite PRN number
    /// IsFixed bool If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class IsBeiDouSatMotionFixedResult;
    typedef std::shared_ptr<IsBeiDouSatMotionFixedResult> IsBeiDouSatMotionFixedResultPtr;
    
    
    class IsBeiDouSatMotionFixedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsBeiDouSatMotionFixedResult();

      IsBeiDouSatMotionFixedResult(CommandBasePtr relatedCommand, int prn, bool isFixed);
  
      static IsBeiDouSatMotionFixedResultPtr create(CommandBasePtr relatedCommand, int prn, bool isFixed);
      static IsBeiDouSatMotionFixedResultPtr dynamicCast(CommandBasePtr ptr);
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

