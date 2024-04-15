#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------------------------------------------
    /// Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
    /// Val   double Coefficient value.
    ///

    class SetEffectiveIonisationLevelCoefficient;
    typedef std::shared_ptr<SetEffectiveIonisationLevelCoefficient> SetEffectiveIonisationLevelCoefficientPtr;
    
    
    class SetEffectiveIonisationLevelCoefficient : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetEffectiveIonisationLevelCoefficient();

      SetEffectiveIonisationLevelCoefficient(int index, double val);

      static SetEffectiveIonisationLevelCoefficientPtr create(int index, double val);
      static SetEffectiveIonisationLevelCoefficientPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
    
  }
}

