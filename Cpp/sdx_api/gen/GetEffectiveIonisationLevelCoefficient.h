#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------------------
    /// Index int  Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
    ///

    class GetEffectiveIonisationLevelCoefficient;
    typedef std::shared_ptr<GetEffectiveIonisationLevelCoefficient> GetEffectiveIonisationLevelCoefficientPtr;
    
    
    class GetEffectiveIonisationLevelCoefficient : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEffectiveIonisationLevelCoefficient();

      GetEffectiveIonisationLevelCoefficient(int index);

      static GetEffectiveIonisationLevelCoefficientPtr create(int index);
      static GetEffectiveIonisationLevelCoefficientPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);
    };
    
  }
}

