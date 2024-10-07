#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/SignalWithComponent.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetInterModulation.
    ///
    /// Name        Type                      Description
    /// ----------- ------------------------- -------------------------
    /// SignalArray array SignalWithComponent Signals to multiply.
    /// Coefficient double                    The coefficient to apply.
    ///

    class GetInterModulationResult;
    typedef std::shared_ptr<GetInterModulationResult> GetInterModulationResultPtr;
    
    
    class GetInterModulationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetInterModulationResult();

      GetInterModulationResult(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient);

      GetInterModulationResult(CommandBasePtr relatedCommand, const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient);

      static GetInterModulationResultPtr create(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient);

      static GetInterModulationResultPtr create(CommandBasePtr relatedCommand, const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient);
      static GetInterModulationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** signalArray ****
      std::vector<Sdx::SignalWithComponent> signalArray() const;
      void setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray);


      // **** coefficient ****
      double coefficient() const;
      void setCoefficient(double coefficient);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetInterModulationResult);
  }
}

