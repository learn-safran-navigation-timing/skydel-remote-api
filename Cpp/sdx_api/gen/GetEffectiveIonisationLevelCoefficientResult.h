#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEffectiveIonisationLevelCoefficient.
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------------------------------------------
    /// Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
    /// Val   double Coefficient value.
    ///

    class GetEffectiveIonisationLevelCoefficientResult;
    typedef std::shared_ptr<GetEffectiveIonisationLevelCoefficientResult> GetEffectiveIonisationLevelCoefficientResultPtr;
    
    
    class GetEffectiveIonisationLevelCoefficientResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEffectiveIonisationLevelCoefficientResult();

      GetEffectiveIonisationLevelCoefficientResult(int index, double val);

      GetEffectiveIonisationLevelCoefficientResult(CommandBasePtr relatedCommand, int index, double val);

      static GetEffectiveIonisationLevelCoefficientResultPtr create(int index, double val);

      static GetEffectiveIonisationLevelCoefficientResultPtr create(CommandBasePtr relatedCommand, int index, double val);
      static GetEffectiveIonisationLevelCoefficientResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetEffectiveIonisationLevelCoefficientResult);
  }
}

